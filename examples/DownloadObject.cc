// MinIO C++ Library for Amazon S3 Compatible Cloud Storage
// Copyright 2022 MinIO, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "client.h"

int main() {
  // Create S3 base URL.
  minio::s3::BaseUrl base_url("play.min.io");

  // Create credential provider.
  minio::creds::StaticProvider provider(
      "Q3AM3UQ867SPQQA43P2F", "zuf+tfteSlswRu7BJ86wekitnifILbZam1KYY3TG");

  // Create S3 client.
  minio::s3::Client client(base_url, &provider);

  // Create download object arguments.
  minio::s3::DownloadObjectArgs args;
  args.bucket = "my-bucket";
  args.object = "my-object";
  args.filename = "my-object.csv";

  // Call download object.
  minio::s3::DownloadObjectResponse resp = client.DownloadObject(args);

  // Handle response.
  if (resp) {
    std::cout << "my-object is successfully downloaded to my-object.csv"
              << std::endl;
  } else {
    std::cout << "unable to download object; " << resp.Error().String()
              << std::endl;
  }

  return 0;
}

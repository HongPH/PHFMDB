

Pod::Spec.new do |spec|


spec.name         = "PHFMDB"
spec.version      = "1.0.1"
spec.summary      = "A short description."
spec.description  = <<-DESC
it is just a test for PFMDBFramework
DESC
spec.homepage     = "https://github.com/HongPH/PHFMDB"
spec.license      = { :type => 'MIT' }
spec.author       = { "hongpeihao" => "402933963@qq.com" }
spec.platform     = :ios, "8.0"
# spec.source       = { :git => "https://github.com/HongPH/PHFMDB.git", :tag => "#{spec.version}" }
spec.source_files  = "lib/PFMDBFramework.framework/Headers/*.{h}"
spec.vendored_frameworks = "lib/PFMDBFramework.framework"
spec.framework  = "UIKit"


end

from CRABClient.UserUtilities import config
config = config()


config.General.requestName = 'modKF_ScoutingSelection_2025_398801_3'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'kbmtFlatTableProducer_cfg.py'
config.JobType.allowUndistributedCMSSW = True

#config.Data.inputDataset = "/L1Scouting/Run2024G-v1/L1SCOUT"
config.Data.inputDataset = "/L1ScoutingSelection/Run2025G-v1/L1SCOUT"
config.Data.runRange = '398801-398803'
config.Data.inputDBS = "global"
config.Data.splitting = 'Automatic'
config.Data.lumiMask = 'https://cms-service-dqmdc.web.cern.ch/CAF/certification/Collisions25/Cert_Collisions2025_391658_398903_Muon.json'
#config.Data.outLFNDirBase = '/store/group/cmst3/group/slowmuons/Mu8Skim/'
config.Data.outLFNDirBase = '/store/user/flarover/CRAB_DATA'
config.Data.publication = False
config.Site.storageSite = 'T3_CH_CERNBOX'



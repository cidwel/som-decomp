.setcpu "65816"
.segment "CODE"
.org $6BDD
party_status_hero0_portrait = $5ED0
party_status_hero1_portrait = $5ED4
party_status_hero2_portrait = $5EE3
native_party_status_portrait_targets:
    .word party_status_hero0_portrait, party_status_hero1_portrait, party_status_hero2_portrait

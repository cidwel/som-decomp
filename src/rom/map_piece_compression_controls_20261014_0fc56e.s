.setcpu "65816"
.segment "CODE"
.org $C56E
map_control_0fc56e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

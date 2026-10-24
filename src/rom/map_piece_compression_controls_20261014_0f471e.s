.setcpu "65816"
.segment "CODE"
.org $471E
map_control_0f471e:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count

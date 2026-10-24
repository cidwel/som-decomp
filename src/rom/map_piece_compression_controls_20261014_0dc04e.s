.setcpu "65816"
.segment "CODE"
.org $C04E
map_control_0dc04e:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count

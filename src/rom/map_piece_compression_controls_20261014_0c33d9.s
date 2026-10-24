.setcpu "65816"
.segment "CODE"
.org $33D9
map_control_0c33d9:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count

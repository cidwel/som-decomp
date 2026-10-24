.setcpu "65816"
.segment "CODE"
.org $C581
map_control_0dc581:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count

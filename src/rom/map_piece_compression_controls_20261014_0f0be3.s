.setcpu "65816"
.segment "CODE"
.org $0BE3
map_control_0f0be3:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

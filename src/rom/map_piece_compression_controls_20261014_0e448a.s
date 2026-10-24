.setcpu "65816"
.segment "CODE"
.org $448A
map_control_0e448a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

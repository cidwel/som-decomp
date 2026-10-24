.setcpu "65816"
.segment "CODE"
.org $D48B
map_control_0ed48b:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $0C0B
map_control_0d0c0b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count

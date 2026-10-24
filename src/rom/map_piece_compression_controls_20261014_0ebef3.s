.setcpu "65816"
.segment "CODE"
.org $BEF3
map_control_0ebef3:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count

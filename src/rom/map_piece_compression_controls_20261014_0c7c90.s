.setcpu "65816"
.segment "CODE"
.org $7C90
map_control_0c7c90:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count

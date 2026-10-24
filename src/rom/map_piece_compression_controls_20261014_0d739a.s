.setcpu "65816"
.segment "CODE"
.org $739A
map_control_0d739a:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count

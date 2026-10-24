.setcpu "65816"
.segment "CODE"
.org $FB55
map_control_0cfb55:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count

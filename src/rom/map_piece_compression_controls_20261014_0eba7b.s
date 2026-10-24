.setcpu "65816"
.segment "CODE"
.org $BA7B
map_control_0eba7b:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

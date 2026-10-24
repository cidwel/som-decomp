.setcpu "65816"
.segment "CODE"
.org $B7C0
map_control_0eb7c0:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count

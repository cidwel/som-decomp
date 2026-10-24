.setcpu "65816"
.segment "CODE"
.org $B993
map_control_0eb993:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count

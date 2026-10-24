.setcpu "65816"
.segment "CODE"
.org $7658
map_control_0f7658:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count

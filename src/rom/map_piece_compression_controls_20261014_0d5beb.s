.setcpu "65816"
.segment "CODE"
.org $5BEB
map_control_0d5beb:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count

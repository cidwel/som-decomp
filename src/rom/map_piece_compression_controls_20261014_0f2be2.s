.setcpu "65816"
.segment "CODE"
.org $2BE2
map_control_0f2be2:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count

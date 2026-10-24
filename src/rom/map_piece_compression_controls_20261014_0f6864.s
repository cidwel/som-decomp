.setcpu "65816"
.segment "CODE"
.org $6864
map_control_0f6864:
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

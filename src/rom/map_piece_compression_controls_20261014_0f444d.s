.setcpu "65816"
.segment "CODE"
.org $444D
map_control_0f444d:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count

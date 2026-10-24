.setcpu "65816"
.segment "CODE"
.org $3087
map_control_0f3087:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $1945
map_control_0d1945:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count

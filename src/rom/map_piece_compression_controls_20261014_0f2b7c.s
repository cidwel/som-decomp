.setcpu "65816"
.segment "CODE"
.org $2B7C
map_control_0f2b7c:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

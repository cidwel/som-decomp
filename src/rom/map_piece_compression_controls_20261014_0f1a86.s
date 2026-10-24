.setcpu "65816"
.segment "CODE"
.org $1A86
map_control_0f1a86:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $4B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count

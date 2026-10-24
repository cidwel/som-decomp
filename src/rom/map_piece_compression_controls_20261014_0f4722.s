.setcpu "65816"
.segment "CODE"
.org $4722
map_control_0f4722:
    .byte $EC ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

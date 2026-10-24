.setcpu "65816"
.segment "CODE"
.org $633C
map_control_0f633c:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

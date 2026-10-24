.setcpu "65816"
.segment "CODE"
.org $4BB5
map_control_0f4bb5:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count

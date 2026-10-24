.setcpu "65816"
.segment "CODE"
.org $C3DC
map_control_0ec3dc:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count

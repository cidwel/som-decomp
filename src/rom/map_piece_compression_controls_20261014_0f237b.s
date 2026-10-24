.setcpu "65816"
.segment "CODE"
.org $237B
map_control_0f237b:
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count

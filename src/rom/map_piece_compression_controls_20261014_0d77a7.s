.setcpu "65816"
.segment "CODE"
.org $77A7
map_control_0d77a7:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count

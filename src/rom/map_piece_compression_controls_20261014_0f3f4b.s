.setcpu "65816"
.segment "CODE"
.org $3F4B
map_control_0f3f4b:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

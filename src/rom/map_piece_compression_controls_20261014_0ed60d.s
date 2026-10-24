.setcpu "65816"
.segment "CODE"
.org $D60D
map_control_0ed60d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $6B ; distance low bit/count

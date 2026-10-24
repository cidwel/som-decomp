.setcpu "65816"
.segment "CODE"
.org $360E
map_control_0f360e:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count

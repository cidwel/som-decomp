.setcpu "65816"
.segment "CODE"
.org $4B7B
map_control_0f4b7b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $40 ; row-distance/count

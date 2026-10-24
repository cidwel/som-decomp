.setcpu "65816"
.segment "CODE"
.org $5D85
map_control_0f5d85:
    .byte $C5 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count

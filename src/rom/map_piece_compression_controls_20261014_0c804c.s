.setcpu "65816"
.segment "CODE"
.org $804C
map_control_0c804c:
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $6D ; row-distance/count

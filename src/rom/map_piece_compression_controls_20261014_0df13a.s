.setcpu "65816"
.segment "CODE"
.org $F13A
map_control_0df13a:
    .byte $C9 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $5E ; row-distance/count

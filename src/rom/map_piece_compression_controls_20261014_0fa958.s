.setcpu "65816"
.segment "CODE"
.org $A958
map_control_0fa958:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $33 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $563A
map_control_0d563a:
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count

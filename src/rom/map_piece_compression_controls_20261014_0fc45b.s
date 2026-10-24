.setcpu "65816"
.segment "CODE"
.org $C45B
map_control_0fc45b:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C6 ; same-value copy count/distance

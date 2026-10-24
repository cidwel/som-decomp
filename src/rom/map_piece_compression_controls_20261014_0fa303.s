.setcpu "65816"
.segment "CODE"
.org $A303
map_control_0fa303:
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count

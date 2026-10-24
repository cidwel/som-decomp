.setcpu "65816"
.segment "CODE"
.org $6BCC
map_control_0e6bcc:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C2 ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $6722
map_control_0f6722:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

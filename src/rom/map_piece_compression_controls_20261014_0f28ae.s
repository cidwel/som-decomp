.setcpu "65816"
.segment "CODE"
.org $28AE
map_control_0f28ae:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count

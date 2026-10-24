.setcpu "65816"
.segment "CODE"
.org $2BBF
map_control_0d2bbf:
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
    .byte $C7 ; same-value copy count/distance

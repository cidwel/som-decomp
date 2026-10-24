.setcpu "65816"
.segment "CODE"
.org $C18C
map_control_0fc18c:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

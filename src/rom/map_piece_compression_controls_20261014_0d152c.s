.setcpu "65816"
.segment "CODE"
.org $152C
map_control_0d152c:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count

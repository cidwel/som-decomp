.setcpu "65816"
.segment "CODE"
.org $5ECC
map_control_0d5ecc:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count

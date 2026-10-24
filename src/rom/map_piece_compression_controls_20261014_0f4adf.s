.setcpu "65816"
.segment "CODE"
.org $4ADF
map_control_0f4adf:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count

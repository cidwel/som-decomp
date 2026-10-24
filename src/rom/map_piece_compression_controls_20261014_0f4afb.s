.setcpu "65816"
.segment "CODE"
.org $4AFB
map_control_0f4afb:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count

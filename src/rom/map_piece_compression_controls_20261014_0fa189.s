.setcpu "65816"
.segment "CODE"
.org $A189
map_control_0fa189:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count

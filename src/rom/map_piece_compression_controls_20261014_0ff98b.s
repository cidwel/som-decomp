.setcpu "65816"
.segment "CODE"
.org $F98B
map_control_0ff98b:
    .byte $E2 ; previous-row copy count

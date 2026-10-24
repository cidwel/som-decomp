.setcpu "65816"
.segment "CODE"
.org $0FBA
map_control_0f0fba:
    .byte $E1 ; previous-row copy count
